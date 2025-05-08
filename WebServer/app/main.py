from fastapi import FastAPI, Request
from starlette.staticfiles import StaticFiles

from .routers import keyValidation #, frontend
app = FastAPI()
app.include_router(keyValidation.router, tags=["auth"]) #il campo tags riporta il nome dell'endpoint (serve per la docs)

