from typing import List

def canFit(containers: List[int], items: List[int], containerIndex: int) -> bool:
    if containerIndex == len(containers):
        return True  # All containers have been processed successfully
    for i in range(len(items)):
        if items[i] <= containers[containerIndex]:
            itemHeight = items[i]
            containers[containerIndex] -= itemHeight
            if canFit(containers, items, containerIndex + 1):
                return True
            containers[containerIndex] += itemHeight  # Revert changes
    return False

def main():
    N = int(input("Введите количество контейнеров: "))
    containers = [int(input("Введите высоту каждого контейнера: ")) for _ in range(N)]
    
    M = int(input("Введите количество предметов: "))
    items = [int(input("Введите высоту каждого предмета: ")) for _ in range(M)]
    
    if canFit(containers, items, 0):
        print("Предметы можно разместить в контейнерах так")
    else:
        print("Невозможно разместить предметы в контейнерах без выступа груза")

if __name__ == "__main__":
    main()
