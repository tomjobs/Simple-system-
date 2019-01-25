# block.py -- creation and addition of block chain.
# version 1.1, y19 m01 d25 t21.30.
# recently changed by Heisenberg.


import hashlib
import datetime as date


class Block:

    def __init__(self, index, timestamp, data, previous_hash):
        self.index = index
        self.timestamp = timestamp
        self.data = data
        self.previous_hash = previous_hash
        self.hash = self.hash_block()

    def hash_block(self):
        block_data = str(self.index) + \
                     str(self.timestamp) + \
                     str(self.data) + \
                     str(self.previous_hash)
        sha = hashlib.sha256()
        sha.update(block_data.encode("utf8"))
        return sha.hexdigest()


# Create the block chain and add the genesis block.

def create_genesis_block():
    # Manually construct a block with
    # index zero and arbitrary previous hash
    return Block(0, date.datetime.now(), "Genesis Block", "0")


def next_block(last_block):
    this_index = last_block.index + 1
    this_timestamp = date.datetime.now()
    this_data = "Hey! I'm block " + str(this_index)
    this_hash = last_block.hash
    return Block(this_index, this_timestamp, this_data, this_hash)


block_chain = [create_genesis_block()]
previous_block = block_chain[0]


# Add blocks to the chain.

num_of_blocks_to_add = 20
for i in range(0, num_of_blocks_to_add):

    # Add next block to the chain.
    block_add = next_block(previous_block)
    block_chain.append(block_add)
    previous_block = block_add

    # Tell everyone about it!
    print("Block #{} has been added to the block chain!".format(str(block_add.index)))
    print("Hash: {}\n".format(block_add.hash))
