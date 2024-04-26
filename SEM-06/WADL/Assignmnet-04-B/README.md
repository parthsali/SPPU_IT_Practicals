## Assignment-04-B : Deploying a Web Application on AWS

##### Objective: Deploy your web application (created in the previous assignment) on either AWS VPC or AWS Elastic Beanstalk.

### Choosing Your Deployment Platform:

- **AWS VPC:** Offers greater control over your application's infrastructure but requires more manual configuration. Ideal for complex applications or those with specific security or network requirements.
- **AWS Elastic Beanstalk:** Simplified deployment and management for various web application frameworks. Suitable for quicker deployments and easier scaling.

**Here's an overview of the deployment process for each platform:**

**AWS VPC Deployment:**

**1. Provision Resources:**

- Create a VPC (Virtual Private Cloud) with subnets for your application and database (if using a separate database).
- Launch an EC2 instance in the chosen subnet and configure security groups to allow inbound traffic on the appropriate ports (e.g., HTTP for your web application).
- Optionally, set up an RDS (Relational Database Service) instance within your VPC or use an existing database solution.

**2. Prepare Your Application:**

- Package your application code and dependencies into a format suitable for deployment (e.g., WAR file, Docker image).
- Configure your application to connect to the database (if applicable) using the internal VPC endpoint or private IP address.

**3. Deployment:**

- Use tools like AWS CLI or CodeDeploy to upload your application package to the EC2 instance.
- Configure a startup script or service manager (like systemd) to launch your application automatically upon instance restart.

**4. Access Your Application:**

- Obtain the public IP address of the EC2 instance or create an internet gateway and configure a NAT gateway for internet access if needed.
- Access your application by visiting the public IP address or domain name (if configured) in your web browser.

**AWS Elastic Beanstalk Deployment:**

**1. Create an Application in Beanstalk:**

- Choose a platform and web server (e.g., Python on Apache).
- Configure environment variables or application settings.

**2. Create an Application Version:**

- Upload your application code (e.g., ZIP file).
- Optionally, configure a configuration file or .ebextensions file for further customization.

**3. Create an Environment:**

- Choose an EC2 instance type and configure scaling policies.
- Configure security groups and load balancers (if needed).

**4. Deploy Your Application:**

- Beanstalk automatically deploys your application to the created environment.

**Things to Consider:**

- Security: VPC provides more granular control for security groups and network access. Implement best practices like IAM roles and least privilege for access management.
- Scalability: Both platforms offer options for scaling your application. VPC requires manual configuration (e.g., launching additional instances), while Elastic Beanstalk has built-in auto-scaling features.
- Monitoring: VPC requires setting up your own monitoring tools like CloudWatch logs or third-party solutions. Elastic Beanstalk provides integrated monitoring capabilities.

#### Choosing the right platform depends on your specific needs and expertise level. AWS documentation offers detailed guides for both deployment methods:

- Deploy a Single-Tier PHP Application on Amazon Linux 2 using an Amazon VPC: https://m.youtube.com/watch?v=YiHnOrk3TVE
- Deploying with AWS Elastic Beanstalk: https://docs.aws.amazon.com/elasticbeanstalk/latest/dg/applications-console.html
