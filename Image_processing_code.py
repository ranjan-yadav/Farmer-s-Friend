import cv2
import numpy as np
from matplotlib import pyplot as plt
from time import sleep
from smbus import SMBus
addr = 0x8 
bus = SMBus(1)

def image_cap():
    print("Now capturing image...")
    capture = cv2.VideoCapture(0) # starts Capturing
    check,images = capture.read()
    inputimg = images
    counting = 0
    print("image captured!")
    print("Now processing image")

    l_b = np.array([88,0,0])
    u_b = np.array(([200,255,255]))

    mask = np.zeros(images.shape[:2], np.uint8)
    bgdModel = np.zeros((1, 65), np.float64)
    fgdModel = np.zeros((1, 65), np.float64)
    w = images.shape[1]
    h = images.shape[0]
    rect = [0, 0, w-1, h-1]
    cv2.grabCut(images, mask, rect, bgdModel, fgdModel, 1, cv2.GC_INIT_WITH_RECT)
    final_mask = np.where((mask == 0) | (mask == 2), 0, 1).astype('uint8')
    images = images*final_mask[:, :, np.newaxis]
    preresult = images

    iter1 = images.flatten()
    count1 = 0
    for j in iter1:
        if j != 0:
            count1 += 1

    images = cv2.cvtColor(images, cv2.COLOR_RGB2BGR)

    hsv = (cv2.cvtColor(images, cv2.COLOR_BGR2HSV))  # pest detection parameters
    pest_detect_mask = (cv2.inRange(hsv, l_b, u_b))  # pest detection parameters
    result = (cv2.bitwise_and(images, images, mask=pest_detect_mask))


    iter2 = result.flatten()
    count2 = 0
    for j in iter2:
        if j != 0:
            count2 += 1
    percent = (count2/count1)*100
    print("Image Processed")
    print('percentage of affected area =', percent)


    inputimg = cv2.cvtColor(inputimg, cv2.COLOR_BGR2RGB)
    preresult = cv2.cvtColor(preresult, cv2.COLOR_BGR2RGB)

    plt.subplot(1, 3, 1), plt.imshow(inputimg)
    plt.title('Input Image', y=1)
    plt.axis('off')

    plt.subplot(1, 3, 2), plt.imshow(preresult)
    plt.title('Leaf Detection', y=1)
    plt.axis('off')

    plt.subplot(1, 3, 3), plt.imshow(result)
    plt.title('% affected =' + str(percent), y=1)
    plt.axis('off')

    plt.show()
    motor()

def motor():
    print("moving to the next location")
    bus.write_byte(addr, 0x1)
    sleep(8)
    bus.write_byte(addr, 0x0)
    print("Reached Next Location \n")
    sleep(5)

for i in range(2):
    image_cap()

