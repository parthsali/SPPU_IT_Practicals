## Assignment-02-A : Setting Up Version Control with Git and GitHub

#### This guide outlines the steps to create a version control account on GitHub and use Git commands to manage your code effectively:

**1. Create a GitHub Account:**

- Visit https://github.com and sign up for a free account.
- Follow the on-screen instructions to complete your registration.

**2. Install Git (if not already installed):**

- **Windows**: Download and install Git for Windows from https://git-scm.com/downloads
- **macOS**: Open Terminal and run `xcode-select --install` to install Git through Xcode command line tools. Alternatively, download and install Git from https://git-scm.com/download/mac.
- **Linux**: Use your distribution's package manager to install Git (e.g., `sudo apt install git` on Ubuntu/Debian, `sudo yum install git` on CentOS/RHEL).

**3. Initialize a Git Repository in Your Project Directory:**

- Open a terminal or command prompt and navigate to your project directory using the `cd` command (e.g., `cd my-project`).
- Run `git init` to create a new Git repository in the current directory. This creates a hidden `.git` folder that stores version control information.

**4. Stage Changes for Version Control:**

- Use `git add <filename>` to add specific files to the staging area for the next commit.
- Use `git add .` to add all tracked files (those already included in the Git repository) to the staging area.

**5. Commit Your Staged Changes:**

- Run `git commit -m "<commit message>"` to create a snapshot of your current project state with a descriptive commit message. For example, `git commit -m "Added user registration functionality"`.

**6. Create a Remote Repository on GitHub:**

- Go to your GitHub account and click "New repository" to create a new repository.
  Give your repository a name and initialize it with a README file (optional).
- Copy the HTTPS clone URL provided for your repository.

**7. Connect Your Local Repository to GitHub (Push Your Code):**

- In your terminal, run `git remote add origin <repository URL>` to add the copied URL as your remote repository named "origin".
- Run `git push -u origin main` to push your local commits to the `main` branch (or your preferred branch) on the remote GitHub repository.

**Additional Notes:**

- Use `git status` to check the status of your working directory and staging area.
- Use `git log` to view the history of your commits.
- Use `git branch` to manage branches (create, switch, delete).
- Use `git clone <repository URL>` to clone an existing repository from GitHub to your local machine.

**Helpful Links:**

- **GitHub Help**: https://docs.github.com/en/get-started
- **Git SCM Documentation**: https://git-scm.com/

**Remember:**

- This is a basic example. Explore Git's vast features for more advanced version control.
- Secure your GitHub account with a strong password and two-factor authentication.
