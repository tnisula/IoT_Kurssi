// app.js - NodeJS server for the temperature measurement project.

/* 
Parses temperature data from DS18B20 temperature sensor.

Timo Nisula 15/05/2017
*/

// Load node modules
var fs = require('fs');

var express = require('express');
var app = express();

// Setup database connection for logging
var dbObject;
var MongoClient = require('mongodb').MongoClient;
// var assert = require('assert');
// var ObjectId = require('mongodb').ObjectID;
var url = "mongodb://localhost:27017/temperatures";

MongoClient.connect(url, function(err, db) {
   
   if(err) throw err;
   dbObject = db;
});     

// Write a single temperature record in JSON format to database
function insertTemp(data){

   console.log("insertTemp : %s" , JSON.stringify(data));

   dbObject.collection('temps').insertOne(data, function(err, result) {
      
      if(err) throw err;
      console.log("Insert success!");
   }); 
};

function getDateTime() {

    var date = new Date();

    var hour = date.getHours();
    hour = (hour < 10 ? "0" : "") + hour;

    var min  = date.getMinutes();
    min = (min < 10 ? "0" : "") + min;

    var sec  = date.getSeconds();
    sec = (sec < 10 ? "0" : "") + sec;

    var year = date.getFullYear();

    var month = date.getMonth() + 1;
    month = (month < 10 ? "0" : "") + month;

    var day  = date.getDate();
    day = (day < 10 ? "0" : "") + day;

    return year + "-" + month + "-" + day + " " + hour + ":" + min + ":" + sec;
};

// Read current temperature from sensor
function readTemp(callback){
 
   fs.readFile('/sys/bus/w1/devices/28-05168586deff/w1_slave', function(err, buffer)
   {
      if (err){
         console.error(err);
         process.exit(1);
      }

      // Read data from file (using fast node ASCII encoding).
      var data = buffer.toString('ascii').split(" "); // Split by space

      // Extract temperature from string and divide by 1000 to give celsius
      var temp  = parseFloat(data[data.length-1].split("=")[1])/1000.0;

      // Round to one decimal place
      temperature = Math.round(temp * 10) / 10;
      
      // Add date/time and temperature value
      var data = {
            dateandtime: getDateTime(),  // Date.now(),
            value: temperature
            };

      // console.log(JSON.stringify(data));

      // Execute call back with data
      callback(data);
   });
};

// Create a wrapper function which we'll use specifically for logging
function logTemp(interval){
      // Call the readTemp function with the insertTemp function as output to get initial reading
      readTemp(insertTemp);
      // Set the repeat interval (milliseconds). 
      // Third argument is passed as callback function to first (i.e. readTemp(insertTemp)).
      setInterval(readTemp, interval, insertTemp);
};

// Start temperature logging (every 5 min).
var msecs = (60 * 5) * 1000; // log interval duration in milliseconds

// Start temperature logging (every 30 sec).
// var msecs = (60 * 0.5) * 1000; // log interval duration in milliseconds
logTemp(msecs);
// Send a message to console
console.log('Server is logging to database at '+msecs+'ms intervals');

// Enable server
app.listen("3300", function() {
    console.log('Server running at http://localhost:3300');
});
