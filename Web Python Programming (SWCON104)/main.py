import http.server
import socketserver

Handler = http.server.SimpleHTTPRequestHandler
PORT = 80

httpd = socketserver.TCPServer(("", PORT), Handler)
print("serving at port", PORT)
httpd.serve_forever()