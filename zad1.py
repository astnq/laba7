def Skobki(str, pos=0, opened=0):
    if pos == len(str):
        return opened == 0
    if str[pos] == '(':
        return Skobki(str, pos + 1, opened + 1)
    elif str[pos] == ')':
        if opened > 0:
            return Skobki(str, pos + 1, opened - 1)
        else:
            return False
    else:
        return Skobki(str, pos + 1, opened)

if __name__ == "__main__":
    input_str = input("Введите строку со скобками: ")
    if Skobki(input_str):
        print("Скобки расставлены правильно.")
    else:
        print("Скобки расставлены неправильно.")
