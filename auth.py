from fastapi import HTTPException, Security
from fastapi.security import HTTPBearer, HTTPAuthorizationCredentials

security = HTTPBearer()

def verify_token(credentials: HTTPAuthorizationCredentials = Security(security)):
    if credentials.credentials != "nexcore_admin_key":
        raise HTTPException(status_code=403, detail="Invalid token")
    return credentials.credentials