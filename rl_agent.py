import numpy as np
import random

class ResourceRLAgent:
    def __init__(self, state_size=6, action_size=4):
        self.state_size = state_size
        self.action_size = action_size
        self.epsilon = 1.0
        self.q_table = {} 

    def choose_action(self, state_hash):
        if np.random.rand() <= self.epsilon:
            return random.randrange(self.action_size)
        return np.argmax(self.q_table.get(state_hash, [0]*self.action_size))