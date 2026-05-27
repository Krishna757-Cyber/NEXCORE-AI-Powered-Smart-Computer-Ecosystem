import torch
import torch.nn as nn

class ResourcePredictorLSTM(nn.Module):
    def __init__(self, input_dim=6, hidden_dim=64, num_layers=2):
        super(ResourcePredictorLSTM, self).__init__()
        self.lstm = nn.LSTM(input_dim, hidden_dim, num_layers, batch_first=True)
        self.fc = nn.Linear(hidden_dim, input_dim) 
        
    def forward(self, x):
        out, _ = self.lstm(x)
        out = self.fc(out[:, -1, :]) 
        return torch.sigmoid(out)

def forecast_exhaustion(model, metric_sequence):
    model.eval()
    with torch.no_grad():
        prediction = model(torch.tensor(metric_sequence).float())
        return prediction.numpy()