OpenAPI Specification

GET /api/metrics/live

Returns the current system CPU, RAM, and disk utilization.

POST /api/threats/block

Requires Admin JWT. Triggers C-level iptables blocking.
Payload: {"ip_address": "string"}