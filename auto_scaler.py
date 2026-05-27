from cloud_integrator import MultiCloudBridge

class AutoScaler:
    def __init__(self):
        self.bridge = MultiCloudBridge()
        self.active_nodes = []

    def evaluate_load(self, cpu_avg):
        if cpu_avg > 80.0:
            print("[SCALER] High load detected. Scaling out.")
            node = self.bridge.launch_instance("c5.large")
            self.active_nodes.append(node)
        elif cpu_avg < 20.0 and len(self.active_nodes) > 1:
            print("[SCALER] Low load detected. Scaling in.")
            self.active_nodes.pop()