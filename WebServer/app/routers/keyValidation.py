from fastapi import APIRouter, HTTPException

from ..models.authKey import AuthKey
from ..data.authKeys_exampleDB import valid_keys


router = APIRouter(prefix="/auth")

@router.post("/auth")
def validate_auth_key(auth_key: AuthKey):
    '''Checks if the auth key is valid.'''
    if auth_key in list(valid_keys.values()):
        return "Authorization granted."
    else:
        raise HTTPException(status_code=401, detail="Invalid auth key.")

