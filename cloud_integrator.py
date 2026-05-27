class MultiCloudBridge:
    def __init__(self, provider="AWS"):
        self.provider = provider

    def launch_instance(self, instance_type="t3.micro"):
        print(f"[{self.provider}] Provisioning {instance_type}...")
        return "i-0abcdef1234567890"

    def trigger_backup(self, payload):
        print(f"[{self.provider}] Encrypting and syncing data to object storage...")
        return True