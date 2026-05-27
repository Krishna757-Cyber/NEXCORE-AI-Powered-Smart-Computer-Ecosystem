import numpy as np
from sklearn.ensemble import IsolationForest

class SystemAnomalyDetector:
    def __init__(self, contamination_rate=0.05):
        self.model = IsolationForest(
            n_estimators=100, 
            contamination=contamination_rate,
            random_state=42
        )
        self.is_trained = False

    def train_baseline(self, historical_data):
        self.model.fit(historical_data)
        self.is_trained = True

    def anomaly_score(self, current_metrics: list) -> dict:
        if not self.is_trained:
            return {"status": "UNTRAINED"}
            
        data = np.array(current_metrics).reshape(1, -1)
        pred = self.model.predict(data)[0]
        score = self.model.decision_function(data)[0]
        
        return {
            "status": "CRITICAL" if pred == -1 else "NORMAL",
            "anomaly_score": float(-score)
        }
    