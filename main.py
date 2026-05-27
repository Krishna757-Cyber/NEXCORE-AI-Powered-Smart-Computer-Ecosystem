from fastapi import FastAPI, Depends
from models import SystemMetrics
from auth import verify_token

app = FastAPI(title="NEXCORE Gateway")

@app.get("/api/metrics/live", response_model=SystemMetrics)
async def get_metrics(token: str = Depends(verify_token)):
    return SystemMetrics(cpu_percent=45.2, memory_usage_mb=8192)

@app.post("/api/threats/block")
async def block_ip(ip: str, token: str = Depends(verify_token)):
    return {"status": "blocked", "ip": ip}