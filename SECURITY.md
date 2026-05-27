Security & Threat Model

Defenses

Network: AF_PACKET raw socket inspection for unauthorized scans.

Application: Strict JWT bearer validation.

Data: In-transit TLS 1.3 enforcement across all API endpoints.

Note: Avoid running Orchestrator as root unless required for specific C-bindings.
