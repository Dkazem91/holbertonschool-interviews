#!/usr/bin/python3
#dictionary of dictionaries and API calls
import json
import requests
f = open("todo_all_employees.json", "w")
send = {}
ids = requests.get('https://jsonplaceholder.typicode.com/users').json()
tasks = requests.get('https://jsonplaceholder.typicode.com/todos').json()
for person in ids:
    username = person['username']
    info = [
        {'username': username, 'task': task['title'],
         'completed': task['completed']} for task in tasks
        if task['userId'] == person['id']]
    send[person['id']] = info
json.dump(send, f)
