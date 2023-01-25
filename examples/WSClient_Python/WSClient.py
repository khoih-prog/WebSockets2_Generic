# Run by $ python3.8 WSClient.py
# From websocket-client package. Install by $ pip3 install websocket-client
import websocket
import time

ws = websocket.WebSocket()
# For AsyncWebSockets
#ws.connect("ws://192.168.2.118/ws")
# For WebSockets2_Generic
#ws.connect("ws://192.168.2.118:8080")

while True:
    # For WebSockets2_Generic. Change according to your WS Server
    ws.connect("ws://192.168.2.118:8080")
    ws.send("Hello, Server")
    result = ws.recv()
    print(result)
    time.sleep(10)

