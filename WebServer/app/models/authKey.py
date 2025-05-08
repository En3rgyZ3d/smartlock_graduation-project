from pydantic import BaseModel, Field
from typing import Annotated

class AuthKey(BaseModel):
    key: str