from flask import Flask, request, jsonify, send_from_directory
from dotenv import load_dotenv
import os

# Load environment variables from .env file
load_dotenv()

app = Flask(__name__)

# Store sensor data
sensor_data = {
    "soilMoisture": 0,
    "temperature": 0,
    "humidity": 0
}

@app.route('/')
def index():
    return send_from_directory(os.path.join(app.root_path, 'public'), 'index.html')

@app.route('/data', methods=['GET', 'POST'])
def data():
    global sensor_data
    if request.method == 'POST':
        sensor_data = request.json
        return '', 204
    return jsonify(sensor_data)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)