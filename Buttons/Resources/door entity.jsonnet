local common = import "common.jsonnet";

function(params) {
  components: {
    Activation: {
      speed: 4
    },
    Door: {},
    DoorRendering: {},
    Transform: {},
    PhysicsBody: common.getOrientTransform(params) + {
      body: "door body.json"
    },
    PowerInput: common.getPowerInput(params)
  }
}
