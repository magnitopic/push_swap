def canConstruct(string, letters):
    if string == "":
        return True
    for i in letters:
        if (not string.find(i)):
            newString = string[len(i):len(string)]
            if (canConstruct(newString, letters)):
                return True 

    return False


if __name__ == "__main__":
    print(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]))
