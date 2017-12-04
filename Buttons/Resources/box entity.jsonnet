function(params) {
  components: {
    BoxRendering: {},
    Transform: {},
    PhysicsBody: {
      body: "box body.json",
      [if "pos" in params then "pos"]: params.pos,
      [if "size" in params then "scale"]: params.size
    }
  }
}
