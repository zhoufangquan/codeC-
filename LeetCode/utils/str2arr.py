def get_array(data):
    if data[:2] == '[[':
        data = data.strip('[[').strip(']]')
        data = data.split('],[')
        data = [list(map(int, i.split(','))) for i in data]
        return data
    else:
        data = data.strip('[').strip(']')
        data = list(map(int, data.split(',')))
        return data

if __name__ == '__main__':
    data = input()
    data = get_array(data)
    for i in data:
        print(i)
