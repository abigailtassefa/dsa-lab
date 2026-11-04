def cli(error=None):
  if error:
    response = input("Invalid Entry! Please enter a valid key \n")
    responseProcessor(response)
  else:
    print("Welcome brother, what would you like to do today")
    print("For linear search press A")
    print("For binary search press B")
    print("For simple sort, press C")
    response = input("For bubble sort press D \n")
    responseProcessor(response)


def acceptNumbers():
  array = [int(x.strip()) for x in input("Enter the list of numbers you want to process: ").split(",")]
  print(array)
  return array


def acceptTarget():
  return int(input("Enter the number you want to search for: "))


def presentArray(array):
  print(f"The sorted array is {array}")


def presentAnswer(answer, n=None, array=None):
  if isinstance(answer, (tuple, list)):
    array, index, n = answer
  else:
    index = answer

  if index == -1:
    print(f"{n} was not found in the array {array}")
  else:
    print(f"{n} was found at index {index} in the array {array}")


def responseProcessor(response):
  choice = response.strip().upper()
  if choice == "A":
    presentAnswer(linearSearch())
  elif choice == "B":
    presentAnswer(binarySearch())
  elif choice == "C":
    presentArray(simpleSort())
  elif choice == "D":
    presentArray(bubbleSort())
  else:
    cli(1)


def simpleSort(array=None):
  if array is None:
    array = acceptNumbers()
  for i in range(0, len(array) - 1):
    min_idx = i
    for j in range(i, len(array)):
      if array[j] < array[min_idx]:
        min_idx = j

    temp = array[i]
    array[i] = array[min_idx]
    array[min_idx] = temp

  return array


def bubbleSort(array=None):
  if array is None:
    array = acceptNumbers()
  wall = len(array)

  while wall > 1:
    for i in range(0, wall - 1):
      if array[i + 1] < array[i]:
        temp = array[i + 1]
        array[i + 1] = array[i]
        array[i] = temp

    wall -= 1

  return array


def linearSearch(array=None, n=None):
  if array is None:
    array = acceptNumbers()
  if n is None:
    n = acceptTarget()

  for i in range(0, len(array)):
    if array[i] == n:
      return array, i, n
  return array, -1, n


def binarySearch(array=None, n=None, l=0, r=None):
  if array is None:
    array = acceptNumbers()
    array = bubbleSort(array)
  if n is None:
    n = acceptTarget()

  if r is None:
    r = len(array) - 1

  if l > r:
    return array, -1, n

  m = (l + r) // 2

  if array[m] == n:
    return array, m, n
  elif array[m] < n:
    return binarySearch(array, n, m + 1, r)
  else:
    return binarySearch(array, n, l, m - 1)


if __name__ == "__main__":
  cli()
