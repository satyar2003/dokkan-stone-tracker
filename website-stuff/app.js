const express = require("express");
const bodyParser = require("body-parser");
const app = express();

app.listen(3000, () => {
    console.log("app.js is running");
});

// server css as static
app.use(express.static(__dirname));

// get our app to use body parser 
app.use(bodyParser.urlencoded({ extended: true }))

app.get("/", (req, res) => {
    res.sendFile(__dirname + "/index.html");
});

app.post('/process', (req, res) => {
    const userStones = parseInt(req.body.stones);
    const userDateTime = req.body.datetime;

    const inputDate = new Date(userDateTime);
    const currentDate = new Date();
    const timeDifference = inputDate.getTime() - currentDate.getTime();
    const daysDifference = Math.floor(timeDifference / (1000 * 60 * 60 * 24)) + 1;

    const totalStones = userStones + daysDifference;
    const formattedDate = inputDate.toLocaleDateString();

    const message = `You will have ${totalStones} stones by ${formattedDate}.`;
    res.send(message);
});