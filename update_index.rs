#! /usr/bin/env run-cargo-script

use std::fs;
use std::io::prelude::*;

fn create_new_index(folders: Vec<String>) {
    let path = "./index.html";

    let mut output =  fs::OpenOptions::new().write(true).append(false).truncate(true).open(path).unwrap(); 

    let mut string_to_write = folders.iter().fold(String::from("<ul>"),|a,i| {
        format!("{0}\n<li><a href=\"{1}\">{1}</a></li>",a.as_str(),i.as_str())
    });
    string_to_write = format!("{}</ul>",string_to_write);


    if let Err(e) = writeln!(output,"{}",string_to_write.as_str()) {
        eprintln!("couldn't write to file");
    }

    }



pub fn main() {

    let paths = fs::read_dir("./").unwrap();
    let mut folders_to_include = vec![];

    for path in paths {
        let rpath = path.unwrap();
        println!("Name: {}",rpath.path().display());
        if rpath.metadata().unwrap().is_dir() {
            let mut test_path =  rpath.path();
            test_path.push("index.html");
            if test_path.exists() {
                println!("found its index.html, plugging it");
                let file_string = String::from(rpath.path().to_str().unwrap());
                folders_to_include.push(file_string);
            }
        }
    }

    create_new_index(folders_to_include);




}
