def Gesture(lm):

    def Open(lm):
        if lm[8].y < lm[6].y and lm[12].y < lm[10].y and lm[16].y < lm[14].y and lm[20].y < lm[18].y:
            return "Open"
        return "none"

    def Close(lm):
        if lm[8].y > lm[6].y and lm[12].y > lm[10].y and lm[16].y > lm[14].y and lm[20].y > lm[18].y:
            return "Close"
        return "none"
    
    gestures = [
        Open(lm),
        Close(lm)
    ]

    for gestures in gestures:
        if gestures != "none":
            return gestures

    return "none"

