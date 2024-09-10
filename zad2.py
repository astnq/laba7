def decode_string(s, i):
    res = ""
    
    while i[0] < len(s) and s[i[0]] != ']':
        if not s[i[0]].isdigit():
            res += s[i[0]]
            i[0] += 1
        else:
            k = 0
            while i[0] < len(s) and s[i[0]].isdigit():
                k = k * 10 + int(s[i[0]])
                i[0] += 1
            
            i[0] += 1  # Пропускаем '['
            decoded_str = decode_string(s, i)
            i[0] += 1  # Пропускаем ']'
            
            res += decoded_str * k

    return res

def decode_string_main(s):
    i = [0]
    return decode_string(s, i)

if __name__ == "__main__":
    s = input("Введите: ")
    print("Вывод:", decode_string_main(s))
