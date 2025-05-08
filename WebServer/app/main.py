from fastapi import FastAPI, Request
from starlette.staticfiles import StaticFiles

from .routers import keyValidation,status #, frontend
app = FastAPI()
app.include_router(keyValidation.router, tags=["auth"]) #il campo tags riporta il nome dell'endpoint (serve per la docs)
app.include_router(status.router, tags=["status"]) #il campo tags riporta il nome dell'endpoint (serve per la docs)

