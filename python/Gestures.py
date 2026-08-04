def Gesture(lm):
    def Forward(lm):
        if lm[8] > lm[7] > lm[5]:
            return "forward"
        if lm[4] > lm[3] > lm[1]:
            return "backward"
        