local common = import "common.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: {
    Activation: {},
    Collision: {},
    LockRendering: {},
    PowerOutput: {},
    Transform: {},
    PhysicsBody: common.getPos(params) + {
      body: "sensor body.json"
    },
    Lock: {
      index: params.index
    }
  }
}
