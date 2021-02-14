FROM node:15-slim

WORKDIR /frontend

RUN npm install -g create-react-app

COPY ./frontend/package.json  ./

RUN npm install
