from sklearn.ensemble import RandomForestClassifier
import numpy as np

class ThreatClassifier:
    def __init__(self):
        self.rf = RandomForestClassifier(n_estimators=50, max_depth=10)
        self.classes = ["BENIGN", "SCAN", "BRUTE_FORCE", "DDOS"]

    def train(self, X, y):
        self.rf.fit(X, y)

    def classify(self, features):
        pred_idx = self.rf.predict([features])[0]
        conf = np.max(self.rf.predict_proba([features]))
        return {"class": self.classes[pred_idx], "confidence": float(conf)}