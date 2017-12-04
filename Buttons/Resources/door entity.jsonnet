local common = import "common components.jsonnet";

function(params) {
  components: {
    Activation: {
      speed: 4
    },
    Door: {},
    DoorRendering: {},
    Transform: {},
    PhysicsBody: common.transformParams(params) + {
      body: "door body.json"
    },
    PowerInput: common.powerInputParams(params)
  }
}
