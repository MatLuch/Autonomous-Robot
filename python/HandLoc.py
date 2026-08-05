import cv2
import mediapipe as mp
import time
import math 
from Gestures import Gesture

mp_hands = mp.solutions.hands
mp_draw = mp.solutions.drawing_utils
hands = mp_hands.Hands(max_num_hands=2, min_detection_confidence=0.7)

cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 1280)
time.sleep(2)

while cap.isOpened():
    success, img = cap.read()
    if not success:
        continue 
    
    img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = hands.process(img_rgb)

    left_hand = "none"
    right_hand = "none"
    
    if results.multi_hand_landmarks:
        for hanLoc, handType in zip(results.multi_hand_landmarks, results.multi_handedness):
            mp_draw.draw_landmarks(img, hanLoc, mp_hands.HAND_CONNECTIONS)
            lm = hanLoc.landmark
            hand = handType.classification[0].label
            gesture = Gesture(lm)


            if hand == "Left":
                left_hand = gesture

            if hand == "Right":
                right_hand = gesture


    print("Left:", left_hand, "Right:", right_hand)

    
    cv2.imshow("Hand Tracking", img)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()