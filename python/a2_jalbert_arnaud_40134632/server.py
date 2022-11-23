"""
COMP348 Assignment 2 Fall 2022
Arnaud Jalbert, 40134632
"""

import socketserver

# to store the database
db_list = {}

class MyTCPHandler(socketserver.BaseRequestHandler):
    """
    The request handler class for our server.
    """

    # receives requests from client
    def handle(self):

        # connection to the client, receives the command and parameters here
        self.data = self.request.recv(1024).strip()

        # parse the request type
        req_type = str(self.data).split(" ")[0].replace("b", "").replace("'", "")

        # parse the arguments given
        req_args = str(self.data).split(" ")[1].replace("'", "")

        # printing the request to the console
        print("Request -> {Type: " + req_type + ", Args : " + req_args +"}")

        # processing the request and storing the response
        response = self.process(req_type, req_args)

        # send back processed data here
        self.request.sendall(bytes(response, "utf-8"))

    # identifies the type of request and processes it accordingly
    def process(self, req_type, req_args):

        response = ""

        if req_type == "find":
            response = self.find_customer(req_args)

        if req_type == "add":
            response = self.add_customer(req_args)

        if req_type == "delete":
            response = self.delete_customer(req_args)

        if req_type == "update":
            response = self.update_customer(req_args)
        
        if req_type == "print":
            response = self.print_report()

        return response

    # finds customer in db, if not there returns error message
    def find_customer(self, req_args):

        if req_args in db_list:
            return self.print_customer(db_list[req_args])
        
        return req_args + " not found in database"

    # adds customer to db, if already there returns error message
    def add_customer(self, req_args):

        # parse the arguments
        customer = req_args.replace("[","").replace("]","").split(";")
        # replace "/" by spaces
        customer[2] = customer[2].replace("/", " ")

        # checking if customer already exists
        if customer[0] in db_list:
            return "Customer " + customer[0] + " already exists."

        # if cusomer does not exist, we appends it to the list(dictionary)
        db_list[customer[0]] = customer

        # return confirmation
        return "Customer " + customer[0] + " added to DB."

    # deletes the customer from db if it exists
    def delete_customer(self, req_args):
        
        if req_args in db_list:
            del db_list[req_args]
            return "Deleted customer " + req_args + " from DB."
                
        return "Customer " + req_args + " does not exist."

    # update the age, address or phone number of customer
    def update_customer(self, req_args):
        
        update = req_args.replace("[","").replace("]","").split(";")
        # update[0] -> name of customer
        # update[1] -> update data
        # update[2] -> which field to update
        
        # check if customer in db
        if update[0] in db_list:
            if update[2] == "age":
                db_list[update[0]][1] = update[1]
            if update[2] == "address":
                update[1] = update[1].replace("/", " ")
                db_list[update[0]][2] = update[1]
            if update[2] == "phone_number":
                db_list[update[0]][3] = update[1]
                
            return "The " + update[2] + " of customer " + update[0] + " has been updated to " + update[1] + "."

        return "Customer " + update[0] + " does not exist."
    
    # prints the content of db
    def print_report(self):
        
        response = "\n** Python DB contents **"

        for customer in db_list.values():
            response = response + "\n" + self.print_customer(customer)
        
        return response

    # create string to store the customer
    def print_customer(self, customer):
        return customer[0] + "|" + customer[1] + "|" + customer[2] + "|" + customer[3]
    
# loads database from txt file
def load_db():

    with open("data.txt", "r") as db:
            
        for line in db:
            #parse the line, remove any new line "\n" and split with "|"
            customer = line.replace("\n", "").split("|")
            
            if customer[0] in db_list:
                print(customer[0] + " has already been imported, not importing it again.")
                continue
            
             # making sure there is at least a name
            if(not customer[0]):
                # we don't add it if no name
                print('This line "' + line + "' has no customer name associated to it, not importing.")
                continue
                
            # making sure that all parameters are there
            if(not len(customer) == 4):
                print('This line "' + line + "' has not all the needed information, not importing it.")
                continue
            
            # removing whitespace at beginning and end
            for i in range(len(customer)):
                customer[i] = customer[i].strip()
            
            # adding line to dictionary    
            db_list[customer[0]] = customer
        
    return db_list

if __name__ == "__main__":

    HOST, PORT = "localhost", 9999

    # load the DB
    db_list = load_db()

    # Create the server, binding to localhost on port 9999
    with socketserver.TCPServer((HOST, PORT), MyTCPHandler) as server:
        # wait for request from the client
        server.serve_forever()