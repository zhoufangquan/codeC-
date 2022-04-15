def getlist(data: str) -> list:
    if data[:2] == '[[':
        data = data.strip('[["').strip('"]]')
        data = data.split('"],["')
        data = [_.split('","') for _ in data]
        return data
    else:
        data = data.strip('["').strip('"]')
        data = data.split('","')
        return data

if __name__ == '__main__':
    data = input()
    data = getlist(data)
    for i in data:
        print(i)