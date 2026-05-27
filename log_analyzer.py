import json

class LogAnalyzer:
    def analyze_syslog(self, logs):
        keywords = ["OOM", "segfault", "panic", "error"]
        issues = [line for line in logs if any(k in line.lower() for k in keywords)]
        
        return json.dumps({
            "critical_events": len(issues),
            "summary": "Detected potential memory corruption" if issues else "Nominal",
            "raw_matches": issues
        })