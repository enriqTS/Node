// GET = Buscar informações 
// POST = Cadastrar informações
// PUT = Atualizar informações de uma entidade
// PATCH = Atualizar uma informação única de uma entidade 
// DELETE = Deletatr uma informação

import express from 'express'
import { routes } from './routes';

const app = express();

app.use(express.json());
app.use(routes);

app.listen(3333, () => {
    console.log('Server running')
});