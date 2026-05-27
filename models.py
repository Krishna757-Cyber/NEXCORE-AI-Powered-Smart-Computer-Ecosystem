from pydantic import BaseModel
from typing import List, Optional

class Alert(BaseModel):
    id: str
    severity: str
    message: str

class SystemMetrics(BaseModel):
    cpu_percent: float
    memory_usage_mb: int
    alerts: Optional[List[Alert]] = []