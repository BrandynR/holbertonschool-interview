#!/usr/bin/node

const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], async function (err, res, body) {
  if (err) {
    console.log(err);
  }
  for (const character of JSON.parse(body).characters) {
    await new Promise((resolve, reject) => {
      request(character, function (err, res, body) {
        if (err) {
          console.log(err);
        }
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
