import socket
import sys

# acceptable commands
COMMANDS = {"1","2","3","4","5","6","7","8"}

HOST, PORT = "localhost", 9999

# sends the request to the server and returns the response
def send_request(request):

    # Create a socket (SOCK_STREAM means a TCP socket)
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:

        # connect to server
        sock.connect((HOST, PORT))

        # send request
        sock.sendall(bytes(request + "\n", "utf-8"))

        # wait for response from the server
        response = str(sock.recv(1024), "utf-8")
        
        # send response back to user
        return response

# displays the menu, it is defined in "menu.txt"
def display_menu():
    
    # empty line
    print()

    # reading menu
    with open("menu.txt") as menu:
        for line in menu:
            # printing options
            print(line)

# prompts user for a command
def get_cmd():

    # empty line
    print()

    # loops until valid command
    while True:
        cmd = input("Select: ")

        # check if the command is accepted
        if cmd in COMMANDS:
            return cmd

        print("Not a valid command, choose a number from the menu.")

def get_request(cmd):
    print()

    # placeholder for request to be sent
    request = None

    # each statement asks for all necessarry information to create the request
    # also checks that they are valid for the type of request made

    # find customer
    if cmd == "1":

        while True:
            name = input("Customer to find: ")

            if check_name(name):
                request = "find " + name
                break

    # add new customer
    if cmd == "2":

        while True:
            name = input("New Customer Name: ")
            age = input("New Customer Age: ")
            address = input("New Customer Address: ")
            phone_number = input("New Customer Phone Number: ")

            if check_new_customer(name, age, address, phone_number):
                request = "add [" + name.split(" ")[0] + ";" + age.split(" ")[0] + ";" + address.replace(" ", "/") + ";" + phone_number.split(" ")[0] + "]"
                break

    # delete customer
    if cmd == "3":

        while True:
            name = input("Customer to delete: ")

            if check_name(name):
                request = "delete " + name
                break

    # update age
    if cmd == "4":

        while True:
            name = input("Customer to update: ")
            update = input("New age of customer: ")

            if check_name(name) and check_age(update):
                request = "update [" + name + ";" + update.split(" ")[0] + ";age]"
                break

    # update address
    if cmd == "5":

       while True:
            name = input("Customer to update: ")
            update = input("New address of customer: ")

            if check_name(name) and check_address(update):
                request = "update [" + name + ";" + update.replace(" ", "/")  + ";address]"
                break

    # update phone number
    if cmd == "6":

       while True:
            name = input("Customer to update: ")
            update = input("New phone number of customer: ")

            if check_name(name) and check_phone_number(update):
                request = "update [" + name + ";" + update.split(" ")[0]+ ";phone_number]"
                break

    # print db
    if cmd == "7":
        request = "print report"
    
    # exits
    if cmd == "8":
        print("\nGoodbye!")
        exit(0)
    
    # empty line
    print()

    # return formatted request
    return request

# all checks to make sure user input is correct
def check_name(name):
    if any(char.isdigit() for char in name):
        print("There should not be any number in the name, please choose a different name.")
        return False
    
    return True
 
def check_age(age):
    if not age.isnumeric():
        print("Please enter a numeric value for the age.")
        return False
    
    return True

def check_address(address):
    if not address.split()[0].isnumeric():
        print("The first value of the address should be a number. Please enter a valid adddress.")
        return False
    
    return True

def check_phone_number(phone_number):
    if not phone_number.replace("-","").replace("(","").replace(")","").isnumeric():
        print("A phone number should only be numeric values and characters '(', ')' and '-'.((###)-###-####)")
        return False
    
    return True

def check_new_customer(name, age, address, phone_number):
    return check_name(name) and check_age(age) and check_address(address) and check_phone_number(phone_number)

# main loop
if __name__ == "__main__":
    
    # user loop, exiting when user selects "Exit"
    while True:

        print("------------------------")
        # displaying the menu
        display_menu()

        # asking cmd from user
        cmd = get_cmd()

        # setting the request to be sent to server
        request = get_request(cmd)

        response = send_request(request)

        print("Server Response: " + response + "\n")


