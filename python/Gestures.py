def Gesture(lm):

    def Forward(lm):
        if lm[8].y < lm[7].y < lm[5].y:
            return "forward"
        return "none"

    def Backward(lm):
        if lm[20].y < lm[19].y < lm[17].y:
            return "backward"
        return "none"

    def Left(lm):
        if lm[12].y < lm[11].y < lm[9].y:
            return "left"
        return "none"

    gestures = [
        Forward(lm),
        Backward(lm),
        Left(lm)
    ]

    for gestures in gestures:
        if gestures != "none":
            return gestures

    return "none"