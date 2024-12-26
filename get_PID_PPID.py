#!/usr/bin/env python3
import os

def main():
    print(f"PID: {os.getpid()}")
    print(f"PPID: {os.getppid()}")

if __name__ == "__main__":
    main()
