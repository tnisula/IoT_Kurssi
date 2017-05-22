var express = require("express");
var bodyparser = require("body-parser");
var path = require("path");
var mongoose = require("mongoose");

var Schema = mongoose.Schema;

var Temp = new Schema({
	dateandtime:String,
	value:Number
	});

var app = express();

mongoose.model("Temp",Temp);
mongoose.connect("mongodb://localhost/temperaturedb");
var TempModel = mongoose.model("Temp"); 
mongoose.Promise = Promise;
app.use(express.static(path.join(__dirname,"public_www")));
app.use(bodyparser.json());

var tempList = [];

app.get("/api/temps",function(req,res) {
	TempModel.find(function(err,items,count) { 
		if(err) {
			console.log("Failed to find anything");
			res.send("Failure");
		} else {
			console.log(items);
			res.send(JSON.stringify(items));
		}
	})
});

app.post("/api/temps", function(req,res) {
	var newtemp = new TempModel({
		dateandtime:req.body.dateandtime,
		value:req.body.value		
	});
	newtemp.save(function(err,item,count){
		if (err) {
			console.log("Save failed");
			res.send("failure");
		} else {
			console.log("Save succeeded!")
			res.send("success");
		}
	})
});

app.listen(3000);
console.log("Running at port 3000");
