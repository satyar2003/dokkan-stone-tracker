const express = require("express");
const bodyParser = require("body-parser");
const app = express();

let format;
let weekend;

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

app.get("/buttonClicked", (req, res) => {
    // console.log("button clicked");
});

app.post('/process', (req, res) => {
    const userStones = parseInt(req.body.stones);
    const userDateTime = req.body.datetime;

    const inputDate = new Date(userDateTime);
    const currentDate = new Date();
    const timeDifference = inputDate.getTime() - currentDate.getTime();
    let daysDifference = Math.floor(timeDifference / (1000 * 60 * 60 * 24)) + 1;

    // const formattedDate = inputDate.toLocaleDateString();

    const currentTime = new Date(currentDate.toLocaleString('en-US', { timeZone: 'America/Los_Angeles' }));
    if (currentTime.getHours() < 17) {
        daysDifference += 1;
    }

    const formattedOutput = format(userStones, daysDifference, weekend(inputDate));
    res.send(formattedOutput);
});

format = function (s, d, w) {
    let columnWidth = 40;
    let dividerLine = "";
    for (let i = 0; i < columnWidth; i++) {
        dividerLine += "-";  
    }
    let output = `
    <div class="output-row">
        <span class="output-label">Current Stones</span>
        <span class="output-value">${s}</span>
    </div>
    <div class="output-row">
        <span class="output-label">Weekend Stones</span>
        <span class="output-value">${w}</span>
    </div>
    <p class="divider-line">${dividerLine}</p>
    <div class="output-row">
        <span class="output-label">Login Bonus</span>
        <span class="output-value">${d}</span>
    </div>
    <div class="output-row">
        <span class="output-label">Special Missions</span>
        <span class="output-value">${d}</span>
    </div>
    <p class="divider-line">${dividerLine}</p>
    <div class="output-row">
        <span class="output-label">Total Stones</span>
        <span class="output-value">${s + d + d + w}</span>
    </div>
    `;

    return output;
};

weekend = function (d) {
    const curr = new Date();
    let weekends = 0;

    if (curr.getDay() === 5) weekends--;
    else if (curr.getDay() === 6) weekends--;

    while (curr <= d) {
        if(curr.getDay() === 5 || curr.getDay() === 6) {
            weekends++;
        }
        curr.setHours(curr.getHours() + 24);
    }

    if (d.getDay() === 5 || d.getDay() === 6) weekends++;

    return weekends;
}