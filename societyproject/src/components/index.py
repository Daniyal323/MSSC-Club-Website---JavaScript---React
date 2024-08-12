transition_table = [
    ['s5', '', '', 's4', '', '', '1', '2', '3'],
    ['', 's6', '', '', '', 'acc', '', '', ''],
    ['', 'r2', 's7', '', 'r2', 'r2', '', '', ''],
    ['', 'r4', 'r4', '', 'r4', 'r4', '', '', ''],
    ['s5', '', '', 's4', '', '', '8', '2', '3'],
    ['', 'r6', 'r6', '', 'r6', 'r6', '', '', ''],
    ['s5', '', '', 's4', '', '', '', '9', '3'],
    ['s5', '', '', 's4', '', '', '', '', '10'],
    ['', 's6', '', '', 's11', '', '', '', ''],
    ['', 'r1', 's7', '', 'r1', 'r1', '', '', ''],
    ['', 'r2', 'r3', '', 'r3', 'r3', '', '', ''],
    ['', 'r3', 'r5', '', 'r5', 'r5', '', '', ''],
]
attributes = {
    'num': 0,
    '+': 1,
    '*': 2,
    '(': 3,
    ')': 4,
    '$': 5,
    'E': 6,
    'T': 7,
    'F': 8
}
productions = {
    1: 'E -> E + T',
    2: 'E -> T',
    3: 'T -> T * F',
    4: 'T -> F',
    5: 'F -> ( E )',
    6: 'F -> num'
}
def parsing(input_string):
    stack = [0]
    input_tokens = input_string.split()
    input_tokens.append('$')
    current_token = input_tokens.pop(0)

    while True:
        state = stack[-1]
        action = transition_table[state][get_column_index(current_token)]

        if action == '':
            return False

        if action == 'acc':
            return True

        if action[0] == 's':
            stack.append(current_token)
            stack.append(int(action[1:]))
            current_token = input_tokens.pop(0)

        elif action[0] == 'r':
            production_number = int(action[1:])
            production = productions[production_number]
            lhs, rhs = production.split(' -> ')

            for _ in range(2 * len(rhs.split())):
                stack.pop()
            state = stack[-1]
            stack.append(lhs)
            stack.append(int(transition_table[state][get_column_index(lhs)]))
        else:
            return False
        print(stack)

def get_column_index(symbol):
    if symbol in attributes:
        return attributes[symbol]
    elif symbol.isdigit():
        return attributes['num']
    else:
        return -1


input_string = '2 * ( 10 + 3 )'
result = parsing(input_string)
print(result)
if result:
    print("String is accepted")
    print(2*(10+3))
else:
    print("String is rejected")

