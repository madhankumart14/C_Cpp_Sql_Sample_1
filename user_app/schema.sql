-- Create the main users table
CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL UNIQUE,
    email TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Seed initial data for testing
INSERT INTO users (username, email) VALUES ('alice_dev', 'alice@example.com');
INSERT INTO users (username, email) VALUES ('bob_coder', 'bob@example.com');
