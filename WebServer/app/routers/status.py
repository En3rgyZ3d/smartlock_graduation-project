from fastapi import APIRouter, HTTPException

router = APIRouter(prefix="/status")

@router.get("/")
def health_check():
    '''Polling to check if the server is running.'''
    return {"status": "OK", "message": "Server is alive"}


