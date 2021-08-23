# Advanced Programming - Task 2

## Instructions

To run the project, I recommend to open the Client and Server repos as separate projects 
because I experienced makelist conflicts if I opened them together.

## Server

A server application that receives a request with user input from the client. 
It prints the input and returns that input to the client as confirmation.

## Client 

A client application that records user input and sends it to the server. 
It receives the input from the server as confirmation of the established 
communication. 

## AbstractCommsLibrary

It was going to provide and abstract interface to both Server and Client.
Due to lack of time, I could not wire in this library, but wanted to demonstrate
the initial idea. 
A copy of the abstract Comms class currently lives in the Server and Client projects. 