# Windows-API-Template
This is a simple game hacking template using the Windows API

# Methods Information and Usage Guide

This document provides detailed information about the various methods available in our API. Each method is designed to facilitate interaction with game processes and memory management efficiently and effectively. The following table includes descriptions, examples, and method signatures for your reference.

## Method Details

| Method                  | Description                                                                                                    | Example                                                                           | Signature                                                                                  |
|-------------------------|----------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------|
| **FindGameProcess**     | Locates the game process by its executable name. This method returns a handle to the process if found.         | `HANDLE handle = FindGameProcess("GameName");`                                    | `HANDLE FindGameProcess(const std::string &gameName);`                                     |
| **FindGameWindow**      | Identifies the game window by its title. This method returns a handle to the window if found.    

