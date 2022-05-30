// GET = Buscar informações 
// POST = Cadastrar informações
// PUT = Atualizar informações de uma entidade
// PATCH = Atualizar uma informação única de uma entidade 
// DELETE = Deletatr uma informação

import express from 'express'
import { prisma } from './prisma';
import nodemailer from 'nodemailer'

const app = express();

app.use(express.json());

const transport = nodemailer.createTransport({
    host: "smtp.mailtrap.io",
    port: 2525,
    auth: {
      user: "841e96d40839c1",
      pass: "9add0cb546740a"
    }
  });

app.post('/feedbacks', async (req, res) =>{
    const { type, comment, screenshot } = req.body;

    const feedback = await prisma.feedback.create({
        data: {
            type,
            comment,
            screenshot
        }
    })

    await transport.sendMail({
        from: 'Equipe Feedget <oi@feedget.com>',
        to: 'Henrique Teixeira <henriqueteixeirasilva16@gmail.com>',
        subject: 'Novo feedback',
        html: [
            `<div style="font-family: sans-serif; font-size: 16px; color: #111;">`,
            `<p>Tipo do Feedback: ${type} </p>`,
            `<p>Comentário: ${comment}</p>`,
            `</div>`
        ].join('\n')
    });
    
    return res.status(201).json({ data: feedback});
});

app.listen(3333, () => {
    console.log('Server running')
});